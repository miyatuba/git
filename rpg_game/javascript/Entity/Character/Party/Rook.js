const ROOK_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/rook_default.png";

Rook = function ()
{
    this.bmp = new createjs.Bitmap(ROOK_IMAGE_DEFAULT_1_PATH);
    this.bmp.scaleX = 0.2;
    this.bmp.scaleY = 0.2;
}

Rook.bmp;

Rook.prototype = new BaseParty();

Rook.prototype.getBmp = function ()
{
    return this.bmp;
}