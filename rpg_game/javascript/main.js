window.addEventListener('load', init);

let render;

//���񏈗�
var Main = function () {
    scene_service = new SceneService();
}

//���[�v
Main.prototype.update = function ()
{
    scene_service.play();
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