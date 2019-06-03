const MAGE_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/mage_default.png";

Mage = function ()
{
    this.bmp = new createjs.Bitmap(MAGE_IMAGE_DEFAULT_1_PATH);
    this.bmp.scaleX = 0.25;
    this.bmp.scaleY = 0.25;

    this.rectCollision = new createjs.Shape();
    this.rectCollision.graphics.setStrokeStyle(1);
    this.rectCollision.graphics.beginStroke("blue");
    this.rectCollision.graphics.drawRect(0, 0, 100, 160);
}

Mage.bmp;
Mage.rectCollision;
Mage.prototype = new BaseParty();

Mage.prototype.getBmp = function ()
{
    return this.bmp;
}

Mage.prototype.getRectCollision = function ()
{
    return this.rectCollision;
}