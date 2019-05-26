Draw = function ()
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
}