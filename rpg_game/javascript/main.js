window.addEventListener('load', init);

let render;


var Main = function () {

}

Main.prototype.update = function ()
{
    console.log('�p�N�`�[');
    return;
};

function init()
{
    main = new Main();
}

function loop() {

    main.update();
    window.requestAnimationFrame(loop);
}

window.requestAnimationFrame(loop);