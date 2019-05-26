const HUNTER_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/hunter_default.png";

Hunter = function ()
{
    this.bmp = new createjs.Bitmap(HUNTER_IMAGE_DEFAULT_1_PATH);
    this.bmp.scaleX = 0.4;
    this.bmp.scaleY = 0.4;
}

Hunter.bmp;

Hunter.prototype = new BaseParty();

Hunter.prototype.getBmp = function ()
{
    return this.bmp;
}