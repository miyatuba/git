const ARCHER_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/archer_default.png";

Archer = function ()
{
    this.bmp = new createjs.Bitmap(ARCHER_IMAGE_DEFAULT_1_PATH);
    this.bmp.scaleX = 0.2;
    this.bmp.scaleY = 0.2;

    this.rectCollision = new createjs.Shape();
    this.rectCollision.graphics.setStrokeStyle(1);
    this.rectCollision.graphics.beginStroke("blue");
    this.rectCollision.graphics.drawRect(0, 0, 100, 160);
}

Archer.bmp;
Archer.rectCollision;
Archer.prototype = new BaseParty();

Archer.prototype.getBmp = function ()
{
    return this.bmp;
}

Archer.prototype.getRectCollision = function ()
{
    return this.rectCollision;
}