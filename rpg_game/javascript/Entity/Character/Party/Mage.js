const MAGE_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/mage_default.png";

Mage = function ()
{
    this.bmp = new createjs.Bitmap(MAGE_IMAGE_DEFAULT_1_PATH);
    this.bmp.scaleX = 0.25;
    this.bmp.scaleY = 0.25;
}

Mage.bmp;

Mage.prototype = new BaseParty();

Mage.prototype.getBmp = function ()
{
    return this.bmp;
}