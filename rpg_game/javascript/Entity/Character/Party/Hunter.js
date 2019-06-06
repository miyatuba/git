const HUNTER_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/hunter_default.png";

class Hunter extends BaseParty
{
    constructor(is_playable) {
        super(is_playable);
        this.bmp = new createjs.Bitmap(HUNTER_IMAGE_DEFAULT_1_PATH);
        this.bmp.scaleX = 0.4;
        this.bmp.scaleY = 0.4;

        this.rectCollision = new createjs.Shape();
        this.rectCollision.graphics.setStrokeStyle(1);
        this.rectCollision.graphics.beginStroke("blue");
        this.rectCollision.graphics.drawRect(0, 0, 100, 160);

        this.party_id = 8;
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

/*Hunter = function (isPlayable)
{
    this.prototype = new BaseParty(isPlayable);
    this.bmp = new createjs.Bitmap(HUNTER_IMAGE_DEFAULT_1_PATH);
    this.bmp.scaleX = 0.4;
    this.bmp.scaleY = 0.4;

    this.rectCollision = new createjs.Shape();
    this.rectCollision.graphics.setStrokeStyle(1);
    this.rectCollision.graphics.beginStroke("blue");
    this.rectCollision.graphics.drawRect(0, 0, 100, 160);
}

Hunter.bmp;
Hunter.rectCollision;

Hunter.prototype.getBmp = function ()
{
    return this.bmp;
}

Hunter.prototype.getRectCollision = function ()
{
    return this.rectCollision;
}*/