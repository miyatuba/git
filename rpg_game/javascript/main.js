window.addEventListener('load', init);

let render;

//初回処理
var Main = function () {
    scene_service = new SceneService();
}

//ループ
Main.prototype.update = function ()
{
    scene_service.play();
    console.log('パクチー');
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