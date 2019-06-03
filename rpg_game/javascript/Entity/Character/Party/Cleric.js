const CLERIC_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/cleric_default.png";

Cleric = function ()
{
    this.bmp = new createjs.Bitmap(CLERIC_IMAGE_DEFAULT_1_PATH);
    this.bmp.scaleX = 0.2;
    this.bmp.scaleY = 0.2;

    this.rectCollision = new createjs.Shape();
    this.rectCollision.graphics.setStrokeStyle(1);
    this.rectCollision.graphics.beginStroke("blue");
    this.rectCollision.graphics.drawRect(0, 0, 100, 160);      
}

Cleric.bmp;
Cleric.rectCollision;
Cleric.prototype = new BaseParty();

Cleric.prototype.getBmp = function ()
{
    return this.bmp;
}

Cleric.prototype.getRectCollision = function ()
{
    return this.rectCollision;
}