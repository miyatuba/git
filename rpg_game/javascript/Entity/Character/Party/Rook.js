const ROOK_IMAGE_DEFAULT_1_PATH = "resource/image/party_character/rook_default.png";

class Rook extends BaseParty
{
    constructor(is_playable)
    {
        var job_type = JobType.createInstanceForRook();
        super(is_playable, job_type);
        this.bmp = new createjs.Bitmap(ROOK_IMAGE_DEFAULT_1_PATH);
        this.bmp.scaleX = 0.2;
        this.bmp.scaleY = 0.2;

        this.party_id = 6;
    }

    getBmp()
    {
        return this.bmp;
    }

}