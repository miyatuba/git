window.addEventListener('load', init);

let render;

function init()
{
    //loadScript('./View/Rnder.js', function () {});
    //let Render = require('./View/Rnder.js');

    render = new Render();
    requestAnimationFrame(update);
}

/*function loadScript(url, callback) {
 var script = document.createElement('script');
 script.type = 'text/javascript';
 script.src = url;

 if (script.readyState) {
 script.onreadystatechange = function () {
 if (script.readyState === 'loaded' || script.readyState === 'complete') {
 script.onreadystatechange = null;
 callback();
 }
 ;
 };
 } else {
 script.onload = function () {
 callback();
 };
 }
 ;

 document.getElementsByTagName('head')[0].appendChild(script);
 };*/

function update()
{
    requestAnimationFrame(update);

    // •`‰æŒn
    render.drawClear();
}



