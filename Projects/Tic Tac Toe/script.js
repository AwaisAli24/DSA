let boxes = document.querySelectorAll(".boxes");
let turnX = true;
let winningPatterns=[[0,1,2],[0,3,6],[0,4,8],
                      []  ]

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
    })
})