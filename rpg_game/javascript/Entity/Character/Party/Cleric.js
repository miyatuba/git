const CLERIC_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/cleric_default.png";

class Cleric extends BaseParty
{
    constructor(is_playable)
    {
        var job_type = JobType.createInstanceForCleric();
        super(is_playable, job_type);
        this.bmp = new createjs.Bitmap(CLERIC_IMAGE_DEFAULT_1_PATH);
        this.bmp.scaleX = 0.2;
        this.bmp.scaleY = 0.2;

        this.party_id = 5;
    }

    getBmp()
    {
        return this.bmp;
    }

}