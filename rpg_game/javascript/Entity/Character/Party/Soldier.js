const SOLDIER_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/soldier_default.png";

class Soldier extends BaseParty
{
    constructor(is_playable)
    {
        super(is_playable);
        this.bmp = new createjs.Bitmap(SOLDIER_IMAGE_DEFAULT_1_PATH);
        this.bmp.scaleX = 0.6;
        this.bmp.scaleY = 0.6;

        this.party_id = 1;

    }

    getBmp()
    {
        return this.bmp;
    }

}