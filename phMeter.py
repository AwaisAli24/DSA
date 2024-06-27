import tkinter as tk
import serial
import threading

class PHMeterApp:
    def __init__(self, master):
        self.master = master
        master.title("pH Meter")

        # Label for displaying the pH value
        self.label = tk.Label(master, text="Waiting for pH value...", font=("Helvetica", 18))
        self.label.pack(pady=20)

        # Label for displaying the water quality
        self.quality_label = tk.Label(master, text="", font=("Helvetica", 16))
        self.quality_label.pack(pady=10)

        try:
            # Configure the serial port - update the port name to the one you are using
            self.ser = serial.Serial('COM3', 9600, timeout=1)
            self.running = True
            self.thread = threading.Thread(target=self.read_from_port)
            self.thread.daemon = True
            self.thread.start()
        except serial.SerialException as e:
            self.label.config(text=str(e))

        self.master.protocol("WM_DELETE_WINDOW", self.on_closing)

    def read_from_port(self):
        while self.running:
            if self.ser.in_waiting > 0:
                line = self.ser.readline().decode('utf-8').strip()
                if line.startswith("pH Val: "):
                    ph_value = line.split(": ")[1]
                    self.update_ph_value(ph_value)

    def update_ph_value(self, ph):
        # Update the label with the pH value
        self.label.config(text=f"pH Value: {ph}")
        try:
            ph_float = float(ph)
            # Determine the quality of the milk based on pH value
            if ph_float < 6.0:
                self.quality_label.config(text="1. Spoiled Milk (Harmful)\n2. Not Good for use (oxytocin High)\n3. Not Fresh", fg="red")
            elif 6.1 <= ph_float <= 6.5:
                self.quality_label.config(text="1. Typically Cows Milk (IF Buffalo milk, its have high contamination)\n2. Slight Acidic (oxytocin Present)\n3. Not Fresh\n4. Have Mild to High Lactose\n5. High Ecoli Ratio (Not good for Children)", fg="orange")
            elif 6.6 <= ph_float <= 7.0:
                self.quality_label.config(text="1. Typically Buffalo milk, (IF Cows, its have LOW Nutritional Values)\n2. Normal for Adult Consumption (oxytocin LOW)\n3. Not Fresh\n4. Have High Lactose\n5. High Ecoli Ratio (Not good for Children)", fg="yellow")
            elif 7.1 <= ph_float <= 7.5:
                self.quality_label.config(text="1. Typically Buffalo milk, (IF Cows, its have Moderate Nutritional Values)\n2. Normal for Adult and Peds Consumption (oxytocin High)\n3. Moderate Fresh\n4. Have High Lactose\n5. Bearable Ecoli Ratio (Ok for Children)", fg="green")
            elif 7.6 <= ph_float <= 8.0:
                self.quality_label.config(text="1. Typically Buffalo milk, (IF Cows, its have Moderate Nutritional Values)\n2. Normal for Adult and Peds Consumption (oxytocin High)\n3. Moderate Fresh\n4. Have High Lactose\n5. Bearable Ecoli Ratio (Ok for Children)", fg="blue")
            elif ph_float > 8.0:
                self.quality_label.config(text="1. Spoiled Milk (Harmful)\n2. Not Good for use (oxytocin High)\n3. Not Fresh\n4. Bacteria Colonies (High)", fg="purple")
        except ValueError:
            self.quality_label.config(text="Invalid pH value.", fg="gray")

    def on_closing(self):
        self.running = False
        self.ser.close()
        self.master.destroy()

def main():
    root = tk.Tk()
    app = PHMeterApp(root)
    root.mainloop()

if __name__ == "__main__":
    main()