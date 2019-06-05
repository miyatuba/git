class Draw
{
    constructor()
    {
        this.stageCreateJS = new createjs.Stage("maincanvas0");
    }

    DrawBmp(bmp, x, y)
    {
        bmp.x = x;
        bmp.y = y;
        this.stageCreateJS.addChild(bmp);
    }

    updateStageCreateJS()
    {
        this.stageCreateJS.update();
    }
}


/*Draw = function ()
{
    this.stageCreateJS = new createjs.Stage("maincanvas0");
}

Draw.stageCreateJS;

Draw.prototype.DrawBmp = function (bmp, x, y)
{

    bmp.x = x;
    bmp.y = y;
    this.stageCreateJS.addChild(bmp);
}

Draw.prototype.updateStageCreateJS = function ()
{
    this.stageCreateJS.update();
}*/