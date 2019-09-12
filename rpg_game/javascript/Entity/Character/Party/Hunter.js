const HUNTER_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/hunter_default.png";

class Hunter extends BaseParty
{
    constructor(is_playable)
    {
        var job_type = JobType.createInstanceForHunter();
        super(is_playable, job_type);
        this.bmp = new createjs.Bitmap(HUNTER_IMAGE_DEFAULT_1_PATH);
        this.bmp.scaleX = 0.4;
        this.bmp.scaleY = 0.4;

        this.party_id = 8;
    }

    getBmp()
    {
        return this.bmp;
    }

}