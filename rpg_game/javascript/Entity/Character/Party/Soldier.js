const SOLDIER_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/soldier_default.png";

class Soldier extends BaseParty
{
    constructor(is_playable)
    {
        super(is_playable);
        this.bmp = new createjs.Bitmap(SOLDIER_IMAGE_DEFAULT_1_PATH);
        this.bmp.scaleX = 0.6;
        this.bmp.scaleY = 0.6;

        this.rectCollision = new createjs.Shape();
        this.rectCollision.graphics.setStrokeStyle(1);
        this.rectCollision.graphics.beginStroke("blue");
        this.rectCollision.graphics.drawRect(0, 0, 100, 160);

        this.party_id = 1;

    }

    getBmp()
    {
        return this.bmp;
    }

    getRectCollision()
    {
        return this.rectCollision;
    }
}

/*Soldier = function (isPlayable)
{
    this.prototype = new BaseParty(isPlayable);
    this.bmp = new createjs.Bitmap(SOLDIER_IMAGE_DEFAULT_1_PATH);
    this.bmp.scaleX = 0.6;
    this.bmp.scaleY = 0.6;

    this.rectCollision = new createjs.Shape();
    this.rectCollision.graphics.setStrokeStyle(1);
    this.rectCollision.graphics.beginStroke("blue");
    this.rectCollision.graphics.drawRect(0, 0, 100, 160);
}

Soldier.bmp;
Soldier.rectCollision;

Soldier.prototype.getBmp = function ()
{
    return this.bmp;
}

Soldier.prototype.getRectCollision = function ()
{
    return this.rectCollision;
}*/