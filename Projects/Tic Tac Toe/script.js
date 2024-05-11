let boxes = document.querySelectorAll(".boxes");
let turnX = true;
let player1 = document.querySelector("#player1");
let player2 = document.querySelector("#player2");
let winMsg = document.querySelector("#win");
let resetButton = document.querySelector("#resetBtn");
let player1Wins=0;
let player2Wins=0;
let pl1=document.querySelector("#pl1");
let pl2=document.querySelector("#pl2");
const winPatterns = [
    [0, 1, 2],
    [0, 3, 6],
    [0, 4, 8],
    [1, 4, 7],
    [2, 5, 8],
    [2, 4, 6],
    [3, 4, 5],
    [6, 7, 8],
  ];

boxes.forEach((box) => {
    box.addEventListener("click",()=>{
        if(turnX){
            box.style.color="#E54F6D";
            box.innerText="X";
            turnX=false;
        }
        else{
            box.style.color="#F8C630";
            box.innerText="O";
            turnX=true;
        }
        box.disabled=true;
        checkWinner();
    })
})
const checkWinner = () => {
    for (let pattern of winPatterns) {
      let pos1Val = boxes[pattern[0]].innerText;
      let pos2Val = boxes[pattern[1]].innerText;
      let pos3Val = boxes[pattern[2]].innerText;
  
      if (pos1Val != "" && pos2Val != "" && pos3Val != "") {
        if (pos1Val === pos2Val && pos2Val === pos3Val) {
          showWinner(pos1Val);
          return true;
        }
      }
    }
  };
const disableBoxes=()=>{
    for(box of boxes){
        box.disabled=true;
    }
}
const showWinner=(winner)=>{
    if(winner=='X'){
        winMsg.innerText += player1.value;
        player1Wins++;
    }
    else{
        winMsg.innerText += player2.value;
        player2Wins++;
    }
    disableBoxes();
}
const resetGame = ()=>{
    for(box of boxes){
        box.disabled=false;
        box.innerText="";
    }
    winMsg.innerText="Winner: ";
    pl1.innerText=`${player1.value}:${player1Wins}`;
    pl2.innerText=`${player2.value}:${player2Wins}`;
}
resetButton.addEventListener("click",resetGame);