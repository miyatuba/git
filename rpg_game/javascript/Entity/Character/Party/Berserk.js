const BERSERK_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/berserk_default.png";

Berserk = function ()
{
    this.bmp = new createjs.Bitmap(BERSERK_IMAGE_DEFAULT_1_PATH);
    this.bmp.scaleX = 0.5;
    this.bmp.scaleY = 0.5;

    this.rectCollision = new createjs.Shape();
    this.rectCollision.graphics.setStrokeStyle(1);
    this.rectCollision.graphics.beginStroke("blue");
    this.rectCollision.graphics.drawRect(0, 0, 100, 160);
}

Berserk.bmp;
Berserk.rectCollision;
Berserk.prototype = new BaseParty();

Berserk.prototype.getBmp = function ()
{
    return this.bmp;
}

Berserk.prototype.getRectCollision = function ()
{
    return this.rectCollision;
}