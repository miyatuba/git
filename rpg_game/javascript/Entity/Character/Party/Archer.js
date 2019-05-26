const ARCHER_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/archer_default.png";

Archer = function ()
{
    this.bmp = new createjs.Bitmap(ARCHER_IMAGE_DEFAULT_1_PATH);
    this.bmp.scaleX = 0.2;
    this.bmp.scaleY = 0.2;
}

Archer.bmp;

Archer.prototype = new BaseParty();

Archer.prototype.getBmp = function ()
{
    return this.bmp;
}