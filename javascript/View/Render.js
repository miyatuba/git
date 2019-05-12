class Render {

    canvas;
    ctx;

    SCREEN_WIDTH = 800;
    SCREEN_HEIGHT = 600;

    constructor()
    {
        this.canvas = document.getElementById('maincanvas');
        this.ctx = this.canvas.getContext('2d');

        this.canvas.width = this.SCREEN_WIDTH;
        this.canvas.height = this.SCREEN_HEIGHT;
    }

    drawClear()
    {
        this.ctx.clearRect(0, 0, this.canvas.width, this.canvas.height); //âÊñ ÇÉNÉäÉAÇ∑ÇÈÅB
    }

}