const ARCHER_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/archer_default.png";

class Archer extends BaseParty
{
    constructor(is_playable)
    {
        var job_type = JobType.createInstanceForArcher();
        super(is_playable, job_type);
        this.bmp = new createjs.Bitmap(ARCHER_IMAGE_DEFAULT_1_PATH);
        this.bmp.scaleX = 0.2;
        this.bmp.scaleY = 0.2;

        this.party_id = 3;
    }

    getBmp()
    {
        return this.bmp;
    }

}
