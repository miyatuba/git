const CLERIC_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/cleric_default.png";

Cleric = function ()
{
    this.bmp = new createjs.Bitmap(CLERIC_IMAGE_DEFAULT_1_PATH);
    this.bmp.scaleX = 0.2;
    this.bmp.scaleY = 0.2;
}

Cleric.bmp;

Cleric.prototype = new BaseParty();

Cleric.prototype.getBmp = function ()
{
    return this.bmp;
}