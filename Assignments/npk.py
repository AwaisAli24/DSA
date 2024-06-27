import tkinter as tk
from tkinter import ttk
import serial
import time
import threading

class NPKApp:
    def __init__(self, root):
        self.root = root
        self.root.title("NPK Sensor Values")

        # Create and place labels for NPK values
        self.nitrogen_label = ttk.Label(root, text="Nitrogen: N/A")
        self.nitrogen_label.grid(row=0, column=0, padx=10, pady=10)

        self.phosphorous_label = ttk.Label(root, text="Phosphorous: N/A")
        self.phosphorous_label.grid(row=1, column=0, padx=10, pady=10)

        self.potassium_label = ttk.Label(root, text="Potassium: N/A")
        self.potassium_label.grid(row=2, column=0, padx=10, pady=10)

        # Serial port settings
        self.serial_port = serial.Serial('/dev/tty.usbserial-1420', 9600, timeout=1)  # Adjust the serial port as needed

        # Start the update loop in a separate thread
        self.update_thread = threading.Thread(target=self.update_values)
        self.update_thread.daemon = True
        self.update_thread.start()

    def update_values(self):
        while True:
            if self.serial_port.in_waiting > 0:
                line = self.serial_port.readline().decode('utf-8').strip()
                if "Nitrogen:" in line:
                    self.nitrogen_label.config(text=line)
                elif "Phosphorous:" in line:
                    self.phosphorous_label.config(text=line)
                elif "Potassium:" in line:
                    self.potassium_label.config(text=line)
            time.sleep(1)

if __name__ == "__main__":
    root = tk.Tk()
    app = NPKApp(root)
    root.mainloop()
