const BERSERK_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/berserk_default.png";

class Berserk extends BaseParty
{
    constructor(is_playable)
    {
        super(is_playable); 
        this.bmp = new createjs.Bitmap(BERSERK_IMAGE_DEFAULT_1_PATH);
        this.bmp.scaleX = 0.5;
        this.bmp.scaleY = 0.5;

        this.rectCollision = new createjs.Shape();
        this.rectCollision.graphics.setStrokeStyle(1);
        this.rectCollision.graphics.beginStroke("blue");
        this.rectCollision.graphics.drawRect(0, 0, 100, 160);  

        this.party_id = 7;
    }

    //ベース側の処理な気がする
    getBmp()
    {
        return this.bmp;
    }

}
