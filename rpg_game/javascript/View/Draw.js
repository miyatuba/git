Draw = function ()
{
    this.stageCreateJS = new createjs.Stage("maincanvas0");
}

Draw.stageCreateJS;

Draw.prototype.DrawBmp = function (bmp, x, y)
{
    bmp1 = new createjs.Bitmap("soldier_default.png");

    bmp1.x = x;
    bmp1.y = y;
    this.stageCreateJS.addChild(bmp1);
}

Draw.prototype.updateStageCreateJS = function ()
{
    this.stageCreateJS.update();
}