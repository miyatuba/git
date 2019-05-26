const LANCER_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/lancer_default.png";

Lancer = function ()
{
    this.bmp = new createjs.Bitmap(LANCER_IMAGE_DEFAULT_1_PATH);
    this.bmp.scaleX = 0.25;
    this.bmp.scaleY = 0.25;
}

Lancer.bmp;

Lancer.prototype = new BaseParty();

Lancer.prototype.getBmp = function ()
{
    return this.bmp;
}