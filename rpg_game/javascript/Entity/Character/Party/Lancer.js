const LANCER_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/lancer_default.png";

class Lancer extends BaseParty
{
    constructor(is_playable)
    {
        var job_type = JobType.createInstanceForLancer();
        super(is_playable, job_type);
        this.bmp = new createjs.Bitmap(LANCER_IMAGE_DEFAULT_1_PATH);
        this.bmp.scaleX = 0.25;
        this.bmp.scaleY = 0.25;

        this.party_id = 2;
    }

    getBmp()
    {
        return this.bmp;
    }

}
