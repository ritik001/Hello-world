var hourHand;
var minuteHand;
var secondHand;


function start_clock()
{
   hourHand= document.getElementById('hour');
   minuteHand = document.getElementById('min');
   secondHand = document.getElementById('sec');
}

function setTime() {

    var date = new Date;
    var hours = date.getHours();
    var minutes = date.getMinutes();
    var seconds = date.getSeconds();
    hours=(hours%12)+minutes/60;
    var secangle = seconds*6;
    var minangle = minutes*6;
    var hourangle = hours*30;
    secondHand.style.transform="rotate(" + secangle + "deg)";
    minuteHand.style.transform="rotate(" + minangle + "deg)";
    hourHand.style.transform="rotate(" + hourangle + "deg)";

}
setInterval(function(){
    setTime();
  }, 1000);
