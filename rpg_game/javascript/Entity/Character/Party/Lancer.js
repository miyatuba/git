const LANCER_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/lancer_default.png";

class Lancer extends BaseParty
{
    constructor(is_playable)
    {
        super(is_playable);
        this.bmp = new createjs.Bitmap(LANCER_IMAGE_DEFAULT_1_PATH);
        this.bmp.scaleX = 0.25;
        this.bmp.scaleY = 0.25;

        this.rectCollision = new createjs.Shape();
        this.rectCollision.graphics.setStrokeStyle(1);
        this.rectCollision.graphics.beginStroke("blue");
        this.rectCollision.graphics.drawRect(0, 0, 100, 160);

        this.party_id = 2;
    }

    getBmp()
    {
        return this.bmp;
    }

}
