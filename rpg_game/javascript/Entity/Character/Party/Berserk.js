const BERSERK_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/berserk_default.png";

Berserk = function ()
{
    this.bmp = new createjs.Bitmap(BERSERK_IMAGE_DEFAULT_1_PATH);
    this.bmp.scaleX = 0.5;
    this.bmp.scaleY = 0.5;
}

Berserk.bmp;

Berserk.prototype = new BaseParty();

Berserk.prototype.getBmp = function ()
{
    return this.bmp;
}