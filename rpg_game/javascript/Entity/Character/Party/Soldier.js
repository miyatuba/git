const SOLDIER_IMAGE_DEFAULT_1_PATH = "resource/image/soldier_default.png";

Soldier = function ()
{
    Soldier.bmp = new createjs.Bitmap(SOLDIER_IMAGE_DEFAULT_1_PATH);
}

Soldier.bmp;

//åpè≥
Soldier.prototype = new BaseParty();

Soldier.prototype.getBmp = function ()
{
    return Soldier.bmp;
}