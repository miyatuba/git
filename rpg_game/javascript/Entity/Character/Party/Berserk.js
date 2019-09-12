const BERSERK_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/berserk_default.png";

class Berserk extends BaseParty
{
    constructor(is_playable)
    {
        var job_type = JobType.createInstanceForBerserk();
        super(is_playable, job_type); 
        this.bmp = new createjs.Bitmap(BERSERK_IMAGE_DEFAULT_1_PATH);
        this.bmp.scaleX = 0.5;
        this.bmp.scaleY = 0.5;

        this.party_id = 7;
    }

    //ベース側の処理な気がする
    getBmp()
    {
        return this.bmp;
    }

}
