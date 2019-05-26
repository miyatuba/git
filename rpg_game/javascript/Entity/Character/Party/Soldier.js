const SOLDIER_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/soldier_default.png";

Soldier = function ()
{
    this.bmp = new createjs.Bitmap(SOLDIER_IMAGE_DEFAULT_1_PATH);
    this.bmp.scaleX = 0.6;
    this.bmp.scaleY = 0.6;
}

Soldier.bmp;

Soldier.prototype = new BaseParty();

Soldier.prototype.getBmp = function ()
{
    return this.bmp;
}