let selects = document.querySelectorAll("select");


for (let select of selects) {
    for (currCode in countryList) {
      let newOption = document.createElement("option");
      newOption.innerText = currCode;
      newOption.value = currCode;
      if (select.name === "from" && currCode === "USD") {
        newOption.selected = "selected";
      } else if (select.name === "to" && currCode === "PKR") {
        newOption.selected = "selected";
      }
      select.append(newOption);
    }
  
    // select.addEventListener("change", (evt) => {
    //   updateFlag(evt.target);
    // });
  }