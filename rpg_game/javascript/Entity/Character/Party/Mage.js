const MAGE_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/mage_default.png";

class Mage extends BaseParty
{
    constructor(is_playable)
    {
        var job_type = JobType.createInstanceForMage();
        super(is_playable, job_type);
        this.bmp = new createjs.Bitmap(MAGE_IMAGE_DEFAULT_1_PATH);
        this.bmp.scaleX = 0.25;
        this.bmp.scaleY = 0.25;

        this.party_id = 4;
    }

    getBmp()
    {
        return this.bmp;
    }

}
