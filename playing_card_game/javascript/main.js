window.addEventListener('load', init);

let render;

function init()
{

    	Asset.loadAssets(function () {
		render = new Render();
		requestAnimationFrame(update);
	});
    
}



function update()
{
    requestAnimationFrame(update);

    // •`‰æŒn
    render.drawClear();
}



