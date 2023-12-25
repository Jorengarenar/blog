const slideNr = window.location.href.split("/").at(-1).replace(".html", "");
document.title = "Esolang: Brainfuck (" + slideNr + ")";

document.addEventListener("DOMContentLoaded", function(){
  const foo = (d) => {
    window.location.href = "./" + String(Number(slideNr) + d).padStart(2, '0') + ".html";
  }

  if (slideNr > 0) {
    const prevbtn = document.createElement("button");
    prevbtn.id = "prevbtn";
    prevbtn.onclick = () => { foo(-1) }
    document.body.appendChild(prevbtn);
  }

  if (!document.body.dataset.last) {
    const nextbtn = document.createElement("button");
    nextbtn.id = "nextbtn";
    nextbtn.onclick = () => { foo(1) }
    document.body.appendChild(nextbtn);
  }
});

document.oncontextmenu = function(e) {
  e.preventDefault();
  document.querySelector("details:not([open])").open = true;
}
