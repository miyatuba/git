const HUNTER_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/hunter_default.png";

Hunter = function ()
{
    this.bmp = new createjs.Bitmap(HUNTER_IMAGE_DEFAULT_1_PATH);
    this.bmp.scaleX = 0.4;
    this.bmp.scaleY = 0.4;

    this.rectCollision = new createjs.Shape();
    this.rectCollision.graphics.setStrokeStyle(1);
    this.rectCollision.graphics.beginStroke("blue");
    this.rectCollision.graphics.drawRect(0, 0, 100, 160);
}

Hunter.bmp;
Hunter.rectCollision;
Hunter.prototype = new BaseParty();

Hunter.prototype.getBmp = function ()
{
    return this.bmp;
}

Hunter.prototype.getRectCollision = function ()
{
    return this.rectCollision;
}