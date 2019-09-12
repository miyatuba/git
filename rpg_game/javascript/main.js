
try {
    window.addEventListener('load', init);
} catch {
    console.log(error.message);
}


var main;

class Main
{
    constructor()
    {
        this.scene_service = new SceneService();
    }

    update()
    {
        this.scene_service.play();
        //console.log('パクチー');
        return;
    }
}


function init()
{
    main = new Main();
}

function loop() {

    main.update();
    window.requestAnimationFrame(loop);
}

window.requestAnimationFrame(loop);