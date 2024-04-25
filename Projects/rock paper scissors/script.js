let choices = document.querySelectorAll(".buttons");
let userChoice=-1;
let computerChoice=-1
let result=-1;
let computerMsg="";
let msg=document.querySelector("#msg");
let msg2=document.querySelector("#sysChoice");
choices.forEach((choice)=>{
    choice.addEventListener("click",()=>{
        userChoice=choice.id;
        computerChoice=Math.floor(Math.random() * 3);
        assignMsg();
        compare();
        winner();
    })
})
const compare=()=>{
    if (userChoice==computerChoice){
        result=0;
    }
    else if(userChoice==0&&computerChoice==1){
        result=1
    }
    else if(userChoice==1&&computerChoice==2){
        result=1
    }
    else if(userChoice==0&&computerChoice==2){
        result=2;
    }
    else if(userChoice==1&&computerChoice==0){
        result=2;
    }
    else if(userChoice==2&&computerChoice==0){
        result=1;
    }
    else if(userChoice==2&&computerChoice==1){
        result=2;
    }
}
const winner= ()=>{
    msg2.innerText=`Computer chose ${computerMsg}.`;
    if(result==0){
        msg.innerText="Draw! You Both Chose The Same.";
    }
    else if(result==1){
        msg.innerText="You Lost, Better Luck Next Time.";
    }
    else if(result==2){
        msg.innerText="You Win, Way to Go.";
    }
}

const assignMsg = ()=>{
    if(computerChoice==0){
        computerMsg="Rock";
    }
    else if(computerChoice==1){
        computerMsg="Paper";
    }
    else if(computerChoice==2){
        computerMsg="Scissor";
    }
}