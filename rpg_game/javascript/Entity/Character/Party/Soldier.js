const SOLDIER_IMAGE_DEFAULT_1_PATH = "./resource/image/soldier_default.png";

Soldier = function ()
{
    Soldier.image.src = SOLDIER_IMAGE_DEFAULT_1_PATH;
}

Soldier.image.src;

//�p��
Soldier.prototype = new BaseParty();