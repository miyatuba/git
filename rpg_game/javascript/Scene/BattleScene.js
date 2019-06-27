class BattleScene {
    BATTLE_BACK_GRAUND_IMAGE = "resource/image/back_graund/back_ground1.jpg";

    PLAYER_CURSOR_1_PATH = "resource/image/battle/player_cursor1.png";
    ENEMY_CURSOR_1_PATH = "resource/image/battle/enemy_cursor1.png";

    PARTY_NUMBER_ID_SOLDIER = 1;
    PARTY_NUMBER_ID_LANCER = 2;
    PARTY_NUMBER_ID_ARCHER = 3;
    PARTY_NUMBER_ID_MAGE = 4;
    PARTY_NUMBER_ID_CLERIC = 5;
    PARTY_NUMBER_ID_ROOK = 6;
    PARTY_NUMBER_ID_BERSERK = 7;
    PARTY_NUMBER_ID_HUNTER = 8;

    PARTY_CHARACTER1_POSITION_X = 480;
    PARTY_CHARACTER1_POSITION_Y = 20;
    PARTY_CHARACTER2_POSITION_X = 450;
    PARTY_CHARACTER2_POSITION_Y = 170;
    PARTY_CHARACTER3_POSITION_X = 570;
    PARTY_CHARACTER3_POSITION_Y = 70;
    PARTY_CHARACTER4_POSITION_X = 570;
    PARTY_CHARACTER4_POSITION_Y = 220;
    PARTY_CHARACTER5_POSITION_X = 700;
    PARTY_CHARACTER5_POSITION_Y = 20;
    PARTY_CHARACTER6_POSITION_X = 700;
    PARTY_CHARACTER6_POSITION_Y = 170;
    PARTY_CHARACTER7_POSITION_X = 820;
    PARTY_CHARACTER7_POSITION_Y = 70;
    PARTY_CHARACTER8_POSITION_X = 820;
    PARTY_CHARACTER8_POSITION_Y = 220;
    PLAYER_CURSOR_RELATIVE_POSITION_X = 100;
    PLAYER_CURSOR_RELATIVE_POSITION_Y = 150;
    
    constructor() {
        this.draw = new Draw();

        this._initPartyDeploy();
        this._initEnemyDeploy();
        this._initDraw();

        
    }

    _initDraw()
    {
        var bmp_back_ground = new createjs.Bitmap(this.BATTLE_BACK_GRAUND_IMAGE);
        bmp_back_ground.scaleX = 1;
        bmp_back_ground.scaleY = 1;
        this.draw.DrawBmp(bmp_back_ground, 0, 0);
        this.draw.DrawBmp(this.party_character1.getBmp(), this.PARTY_CHARACTER1_POSITION_X, this.PARTY_CHARACTER1_POSITION_Y);
        this.draw.DrawBmp(this.party_character1.getRectCollision(), this.PARTY_CHARACTER1_POSITION_X, this.PARTY_CHARACTER1_POSITION_Y);
        this.draw.DrawBmp(this.party_character2.getBmp(), this.PARTY_CHARACTER2_POSITION_X, this.PARTY_CHARACTER2_POSITION_Y);
        this.draw.DrawBmp(this.party_character2.getRectCollision(), this.PARTY_CHARACTER2_POSITION_X, this.PARTY_CHARACTER2_POSITION_Y);
        this.draw.DrawBmp(this.party_character3.getBmp(), this.PARTY_CHARACTER3_POSITION_X, this.PARTY_CHARACTER3_POSITION_Y);
        this.draw.DrawBmp(this.party_character3.getRectCollision(), this.PARTY_CHARACTER3_POSITION_X, this.PARTY_CHARACTER3_POSITION_Y);
        this.draw.DrawBmp(this.party_character4.getBmp(), this.PARTY_CHARACTER4_POSITION_X, this.PARTY_CHARACTER4_POSITION_Y);
        this.draw.DrawBmp(this.party_character4.getRectCollision(), this.PARTY_CHARACTER4_POSITION_X, this.PARTY_CHARACTER4_POSITION_Y);
        this.draw.DrawBmp(this.party_character5.getBmp(), this.PARTY_CHARACTER5_POSITION_X, this.PARTY_CHARACTER5_POSITION_Y);
        this.draw.DrawBmp(this.party_character5.getRectCollision(), this.PARTY_CHARACTER5_POSITION_X, this.PARTY_CHARACTER5_POSITION_Y);
        this.draw.DrawBmp(this.party_character6.getBmp(), this.PARTY_CHARACTER6_POSITION_X, this.PARTY_CHARACTER6_POSITION_Y);
        this.draw.DrawBmp(this.party_character6.getRectCollision(), this.PARTY_CHARACTER6_POSITION_X, this.PARTY_CHARACTER6_POSITION_Y);
        this.draw.DrawBmp(this.party_character7.getBmp(), this.PARTY_CHARACTER7_POSITION_X, this.PARTY_CHARACTER7_POSITION_Y);
        this.draw.DrawBmp(this.party_character7.getRectCollision(), this.PARTY_CHARACTER7_POSITION_X, this.PARTY_CHARACTER7_POSITION_Y);
        this.draw.DrawBmp(this.party_character8.getBmp(), this.PARTY_CHARACTER8_POSITION_X, this.PARTY_CHARACTER8_POSITION_Y);
        this.draw.DrawBmp(this.party_character8.getRectCollision(), this.PARTY_CHARACTER8_POSITION_X, this.PARTY_CHARACTER8_POSITION_Y);
        this.draw.DrawBmp(this.enemy_character_position1.getBmp(), 200, 70);
        this.draw.DrawBmp(this.enemy_character_position2.getBmp(), 200, 220);
        this.draw.DrawBmp(this.enemy_character_position3.getBmp(), 100, 20);
        this.draw.DrawBmp(this.enemy_character_position4.getBmp(), 100, 170);
        this.draw.DrawBmp(this.enemy_character_position5.getBmp(), 0, 70);
        this.draw.DrawBmp(this.enemy_character_position6.getBmp(), 0, 220);

        this.playerableToPartyCursor1Bmp = new createjs.Bitmap(this.PLAYER_CURSOR_1_PATH);
        this.playerableToPartyCursor1Bmp.scaleX = 0.1;
        this.playerableToPartyCursor1Bmp.scaleY = 0.1;
        var playerableToPartyCursorPositionX = 0;
        var playerableToPartyCursorPositionY = 0;
        
        switch (this.getPlayableCharacter().getToPartyTargetPositionNumber()) {
            case 1:
                playerableToPartyCursorPositionX = this.PARTY_CHARACTER1_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                playerableToPartyCursorPositionY = this.PARTY_CHARACTER1_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 2:
                playerableToPartyCursorPositionX = this.PARTY_CHARACTER2_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                playerableToPartyCursorPositionY = this.PARTY_CHARACTER2_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 3:
                playerableToPartyCursorPositionX = this.PARTY_CHARACTER3_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                playerableToPartyCursorPositionY = this.PARTY_CHARACTER3_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 4:
                playerableToPartyCursorPositionX = this.PARTY_CHARACTER4_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                playerableToPartyCursorPositionY = this.PARTY_CHARACTER4_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 5:
                playerableToPartyCursorPositionX = this.PARTY_CHARACTER5_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                playerableToPartyCursorPositionY = this.PARTY_CHARACTER5_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 6:
                playerableToPartyCursorPositionX = this.PARTY_CHARACTER6_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                playerableToPartyCursorPositionY = this.PARTY_CHARACTER6_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 7:
                playerableToPartyCursorPositionX = this.PARTY_CHARACTER7_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                playerableToPartyCursorPositionY = this.PARTY_CHARACTER7_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 8:
                playerableToPartyCursorPositionX = this.PARTY_CHARACTER8_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                playerableToPartyCursorPositionY = this.PARTY_CHARACTER8_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
        }
        this.draw.DrawBmp(this.playerableToPartyCursor1Bmp, playerableToPartyCursorPositionX, playerableToPartyCursorPositionY);


        //各キャラ用に必要
        this.partyToEnemyCursor1Bmp = new createjs.Bitmap(this.ENEMY_CURSOR_1_PATH);
        this.partyToEnemyCursor1Bmp.scaleX = 0.1;
        this.partyToEnemyCursor1Bmp.scaleY = 0.1;
        var partyToEnemyCursorPositionX = 0;
        var partyToEnemyCursorPositionY = 0;
        switch (this.target_enemy_position_number) {
            case 1:
                partyToEnemyCursorPositionX = this.PARTY_CHARACTER7_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                partyToEnemyCursorPositionY = this.PARTY_CHARACTER7_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 2:
                partyToEnemyCursorPositionX = this.PARTY_CHARACTER7_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                partyToEnemyCursorPositionY = this.PARTY_CHARACTER7_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 3:
                partyToEnemyCursorPositionX = this.PARTY_CHARACTER7_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                partyToEnemyCursorPositionY = this.PARTY_CHARACTER7_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 4:
                partyToEnemyCursorPositionX = this.PARTY_CHARACTER7_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                partyToEnemyCursorPositionY = this.PARTY_CHARACTER7_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
        }
        this.draw.DrawBmp(this.partyToEnemyCursor1Bmp, partyToEnemyCursorPositionX, partyToEnemyCursorPositionY);
        

    }

    _initPartyDeploy() {
        this.party_character1 = new Soldier(false);
        this.party_character1.setPartyTargetPositionNumber(1);
        this.party_character1.setEnemyTargetPositionNumber(1);
        this.party_character2 = new Lancer(false);
        this.party_character2.setPartyTargetPositionNumber(1);
        this.party_character2.setEnemyTargetPositionNumber(1);
        this.party_character3 = new Archer(false);
        this.party_character3.setPartyTargetPositionNumber(1);
        this.party_character3.setEnemyTargetPositionNumber(1);
        this.party_character4 = new Mage(false);
        this.party_character4.setPartyTargetPositionNumber(1);
        this.party_character4.setEnemyTargetPositionNumber(1);
        this.party_character5 = new Cleric(false);
        this.party_character5.setPartyTargetPositionNumber(1);
        this.party_character5.setEnemyTargetPositionNumber(1);
        this.party_character6 = new Rook(false);
        this.party_character6.setPartyTargetPositionNumber(1);
        this.party_character6.setEnemyTargetPositionNumber(1);
        this.party_character7 = new Berserk(true);//上手く変動するように変更する
        this.party_character7.setPartyTargetPositionNumber(1);
        this.party_character7.setEnemyTargetPositionNumber(1);
        this.party_character8 = new Hunter(false);
        this.party_character8.setPartyTargetPositionNumber(1);
        this.party_character8.setEnemyTargetPositionNumber(1);
        this.playable_party_id = this.PARTY_NUMBER_ID_BERSERK;
        this.playable_party_position_number = 7;
    }

    _initEnemyDeploy() {
        //多分idを渡してモンスターをインスタンス化するようなfactoryクラスが必要になる予感
        this.enemy_character_position1 = new Goblin;
        this.enemy_character_position2 = new Goblin;
        this.enemy_character_position3 = new Goblin;
        this.enemy_character_position4 = new Goblin;
        this.enemy_character_position5 = new Goblin;
        this.enemy_character_position6 = new Goblin;
    }

    play() {
        //入力処理

        console.log();
        //内部計算
        //表示

        this.draw.updateStageCreateJS();
    }

    input() {
        //メニューを開いたかどうか

        //入力処理（プレイアブル
        switch (this.playable_party_position_number) {
            case 1://流石にここはマジックナンバーで良いと思うんだけど・・
                this._inputPosition1();
                break;
            case 2:
                this._inputPosition2();
                break;
            case 3:
                this._inputPosition3();
                break;
            case 4:
                this._inputPosition4();
                break;
            case 5:
                this._inputPosition5();
                break;
            case 6:
                this._inputPosition6();
                break;
            case 7:
                this._inputPosition7();
                break;
            case 8:
                this._inputPosition8();
                break;
        }

        //味方CPの処理
        //敵CPの処理

        
    }

    _inputPosition1()
    {
        var partyPosition1RectCollision = this.party_character1.getRectCollision();
        partyPosition1RectCollision.addEventListener("click", changePartyTarget1);
        function changePartyTarget1() {
            this.party_character_position1.setPartyTarget(1);
        }
        var partyPosition2RectCollision = this.party_character2.getRectCollision();
        partyPosition2RectCollision.addEventListener("click", changePartyTarget2);
        function changePartyTarget2() {
            this.party_character_position1.setPartyTarget(2);
        }
        var partyPosition3RectCollision = this.party_character3.getRectCollision();
        partyPosition3RectCollision.addEventListener("click", changePartyTarget3);
        function changePartyTarget3() {
            this.party_character_position1.setPartyTarget(3);
        }
        var partyPosition4RectCollision = this.party_character4.getRectCollision();
        partyPosition4RectCollision.addEventListener("click", changePartyTarget4);
        function changePartyTarget4() {
            this.party_character_position1.setPartyTarget(4);
        }
        var partyPosition5RectCollision = this.party_character5.getRectCollision();
        partyPosition5RectCollision.addEventListener("click", changePartyTarget5);
        function changePartyTarget5() {
            this.party_character_position1.setPartyTarget(5);
        }
        var partyPosition6RectCollision = this.party_character6.getRectCollision();
        partyPosition6RectCollision.addEventListener("click", changePartyTarget6);
        function changePartyTarget6() {
            this.party_character_position1.setPartyTarget(6);
        }
        var partyPosition7RectCollision = this.party_character7.getRectCollision();
        partyPosition7RectCollision.addEventListener("click", changePartyTarget7);
        function changePartyTarget7() {
            this.party_character_position1.setPartyTarget(7);
        }
        var partyPosition8RectCollision = this.party_character8.getRectCollision();
        partyPosition8RectCollision.addEventListener("click", changePartyTarget8);
        function changePartyTarget8() {
            this.party_character_position1.setPartyTarget(8);
        }
    }

    _inputPosition2()
    {
        var partyPosition1RectCollision = this.party_character1.getRectCollision();
        partyPosition1RectCollision.addEventListener("click", changePartyTarget1);
        function changePartyTarget1() {
            this.party_character_position2.setPartyTarget(1);
        }
        var partyPosition2RectCollision = this.party_character2.getRectCollision();
        partyPosition2RectCollision.addEventListener("click", changePartyTarget2);
        function changePartyTarget2() {
            this.party_character_position2.setPartyTarget(2);
        }
        var partyPosition3RectCollision = this.party_character3.getRectCollision();
        partyPosition3RectCollision.addEventListener("click", changePartyTarget3);
        function changePartyTarget3() {
            this.party_character_position2.setPartyTarget(3);
        }
        var partyPosition4RectCollision = this.party_character4.getRectCollision();
        partyPosition4RectCollision.addEventListener("click", changePartyTarget4);
        function changePartyTarget4() {
            this.party_character_position2.setPartyTarget(4);
        }
        var partyPosition5RectCollision = this.party_character5.getRectCollision();
        partyPosition5RectCollision.addEventListener("click", changePartyTarget5);
        function changePartyTarget5() {
            this.party_character_position2.setPartyTarget(5);
        }
        var partyPosition6RectCollision = this.party_character6.getRectCollision();
        partyPosition6RectCollision.addEventListener("click", changePartyTarget6);
        function changePartyTarget6() {
            this.party_character_position2.setPartyTarget(6);
        }
        var partyPosition7RectCollision = this.party_character7.getRectCollision();
        partyPosition7RectCollision.addEventListener("click", changePartyTarget7);
        function changePartyTarget7() {
            this.party_character_position2.setPartyTarget(7);
        }
        var partyPosition8RectCollision = this.party_character8.getRectCollision();
        partyPosition8RectCollision.addEventListener("click", changePartyTarget8);
        function changePartyTarget8() {
            this.party_character_position2.setPartyTarget(8);
        }
    }

    _inputPosition3()
    {
        var partyPosition1RectCollision = this.party_character1.getRectCollision();
        partyPosition1RectCollision.addEventListener("click", changePartyTarget1);
        function changePartyTarget1() {
            this.party_character_position3.setPartyTarget(1);
        }
        var partyPosition2RectCollision = this.party_character2.getRectCollision();
        partyPosition2RectCollision.addEventListener("click", changePartyTarget2);
        function changePartyTarget2() {
            this.party_character_position3.setPartyTarget(2);
        }
        var partyPosition3RectCollision = this.party_character3.getRectCollision();
        partyPosition3RectCollision.addEventListener("click", changePartyTarget3);
        function changePartyTarget3() {
            this.party_character_position3.setPartyTarget(3);
        }
        var partyPosition4RectCollision = this.party_character4.getRectCollision();
        partyPosition4RectCollision.addEventListener("click", changePartyTarget4);
        function changePartyTarget4() {
            this.party_character_position3.setPartyTarget(4);
        }
        var partyPosition5RectCollision = this.party_character5.getRectCollision();
        partyPosition5RectCollision.addEventListener("click", changePartyTarget5);
        function changePartyTarget5() {
            this.party_character_position3.setPartyTarget(5);
        }
        var partyPosition6RectCollision = this.party_character6.getRectCollision();
        partyPosition6RectCollision.addEventListener("click", changePartyTarget6);
        function changePartyTarget6() {
            this.party_character_position3.setPartyTarget(6);
        }
        var partyPosition7RectCollision = this.party_character7.getRectCollision();
        partyPosition7RectCollision.addEventListener("click", changePartyTarget7);
        function changePartyTarget7() {
            this.party_character_position3.setPartyTarget(7);
        }
        var partyPosition8RectCollision = this.party_character8.getRectCollision();
        partyPosition8RectCollision.addEventListener("click", changePartyTarget8);
        function changePartyTarget8() {
            this.party_character_position3.setPartyTarget(8);
        }
    }

    _inputPosition4()
    {
        var partyPosition1RectCollision = this.party_character1.getRectCollision();
        partyPosition1RectCollision.addEventListener("click", changePartyTarget1);
        function changePartyTarget1() {
            this.party_character_position4.setPartyTarget(1);
        }
        var partyPosition2RectCollision = this.party_character2.getRectCollision();
        partyPosition2RectCollision.addEventListener("click", changePartyTarget2);
        function changePartyTarget2() {
            this.party_character_position4.setPartyTarget(2);
        }
        var partyPosition3RectCollision = this.party_character3.getRectCollision();
        partyPosition3RectCollision.addEventListener("click", changePartyTarget3);
        function changePartyTarget3() {
            this.party_character_position4.setPartyTarget(3);
        }
        var partyPosition4RectCollision = this.party_character4.getRectCollision();
        partyPosition4RectCollision.addEventListener("click", changePartyTarget4);
        function changePartyTarget4() {
            this.party_character_position4.setPartyTarget(4);
        }
        var partyPosition5RectCollision = this.party_character5.getRectCollision();
        partyPosition5RectCollision.addEventListener("click", changePartyTarget5);
        function changePartyTarget5() {
            this.party_character_position4.setPartyTarget(5);
        }
        var partyPosition6RectCollision = this.party_character6.getRectCollision();
        partyPosition6RectCollision.addEventListener("click", changePartyTarget6);
        function changePartyTarget6() {
            this.party_character_position4.setPartyTarget(6);
        }
        var partyPosition7RectCollision = this.party_character7.getRectCollision();
        partyPosition7RectCollision.addEventListener("click", changePartyTarget7);
        function changePartyTarget7() {
            this.party_character_position4.setPartyTarget(7);
        }
        var partyPosition8RectCollision = this.party_character8.getRectCollision();
        partyPosition8RectCollision.addEventListener("click", changePartyTarget8);
        function changePartyTarget8() {
            this.party_character_position4.setPartyTarget(8);
        }
    }

    _inputPosition5()
    {
        var partyPosition1RectCollision = this.party_character1.getRectCollision();
        partyPosition1RectCollision.addEventListener("click", changePartyTarget1);
        function changePartyTarget1() {
            this.party_character_position5.setPartyTarget(1);
        }
        var partyPosition2RectCollision = this.party_character2.getRectCollision();
        partyPosition2RectCollision.addEventListener("click", changePartyTarget2);
        function changePartyTarget2() {
            this.party_character_position5.setPartyTarget(2);
        }
        var partyPosition3RectCollision = this.party_character3.getRectCollision();
        partyPosition3RectCollision.addEventListener("click", changePartyTarget3);
        function changePartyTarget3() {
            this.party_character_position5.setPartyTarget(3);
        }
        var partyPosition4RectCollision = this.party_character4.getRectCollision();
        partyPosition4RectCollision.addEventListener("click", changePartyTarget4);
        function changePartyTarget4() {
            this.party_character_position5.setPartyTarget(4);
        }
        var partyPosition5RectCollision = this.party_character5.getRectCollision();
        partyPosition5RectCollision.addEventListener("click", changePartyTarget5);
        function changePartyTarget5() {
            this.party_character_position5.setPartyTarget(5);
        }
        var partyPosition6RectCollision = this.party_character6.getRectCollision();
        partyPosition6RectCollision.addEventListener("click", changePartyTarget6);
        function changePartyTarget6() {
            this.party_character_position5.setPartyTarget(6);
        }
        var partyPosition7RectCollision = this.party_character7.getRectCollision();
        partyPosition7RectCollision.addEventListener("click", changePartyTarget7);
        function changePartyTarget7() {
            this.party_character_position5.setPartyTarget(7);
        }
        var partyPosition8RectCollision = this.party_character8.getRectCollision();
        partyPosition8RectCollision.addEventListener("click", changePartyTarget8);
        function changePartyTarget8() {
            this.party_character_position5.setPartyTarget(8);
        }
    }

    _inputPosition6()
    {
        var partyPosition1RectCollision = this.party_character1.getRectCollision();
        partyPosition1RectCollision.addEventListener("click", changePartyTarget1);
        function changePartyTarget1() {
            this.party_character_position6.setPartyTarget(1);
        }
        var partyPosition2RectCollision = this.party_character2.getRectCollision();
        partyPosition2RectCollision.addEventListener("click", changePartyTarget2);
        function changePartyTarget2() {
            this.party_character_position6.setPartyTarget(2);
        }
        var partyPosition3RectCollision = this.party_character3.getRectCollision();
        partyPosition3RectCollision.addEventListener("click", changePartyTarget3);
        function changePartyTarget3() {
            this.party_character_position6.setPartyTarget(3);
        }
        var partyPosition4RectCollision = this.party_character4.getRectCollision();
        partyPosition4RectCollision.addEventListener("click", changePartyTarget4);
        function changePartyTarget4() {
            this.party_character_position6.setPartyTarget(4);
        }
        var partyPosition5RectCollision = this.party_character5.getRectCollision();
        partyPosition5RectCollision.addEventListener("click", changePartyTarget5);
        function changePartyTarget5() {
            this.party_character_position6.setPartyTarget(5);
        }
        var partyPosition6RectCollision = this.party_character6.getRectCollision();
        partyPosition6RectCollision.addEventListener("click", changePartyTarget6);
        function changePartyTarget6() {
            this.party_character_position6.setPartyTarget(6);
        }
        var partyPosition7RectCollision = this.party_character7.getRectCollision();
        partyPosition7RectCollision.addEventListener("click", changePartyTarget7);
        function changePartyTarget7() {
            this.party_character_position6.setPartyTarget(7);
        }
        var partyPosition8RectCollision = this.party_character8.getRectCollision();
        partyPosition8RectCollision.addEventListener("click", changePartyTarget8);
        function changePartyTarget8() {
            this.party_character_position6.setPartyTarget(8);
        }
    }

    _inputPosition7()
    {
        //行動中か同課の確認
        //行動中であればアニメーションを進めてreturn
        //キャラタッチの確認
        var partyPosition1RectCollision = this.party_character1.getRectCollision();
        partyPosition1RectCollision.addEventListener("click", changePartyTarget1);
        function changePartyTarget1() {
            this.party_character_position7.setPartyTarget(1);
        }
        var partyPosition2RectCollision = this.party_character2.getRectCollision();
        partyPosition2RectCollision.addEventListener("click", changePartyTarget2);
        function changePartyTarget2() {
            this.party_character_position7.setPartyTarget(2);
        }
        var partyPosition3RectCollision = this.party_character3.getRectCollision();
        partyPosition3RectCollision.addEventListener("click", changePartyTarget3);
        function changePartyTarget3() {
            this.party_character_position7.setPartyTarget(3);
        }
        var partyPosition4RectCollision = this.party_character4.getRectCollision();
        partyPosition4RectCollision.addEventListener("click", changePartyTarget4);
        function changePartyTarget4() {
            this.party_character_position7.setPartyTarget(4);
        }
        var partyPosition5RectCollision = this.party_character5.getRectCollision();
        partyPosition5RectCollision.addEventListener("click", changePartyTarget5);
        function changePartyTarget5() {
            this.party_character_position7.setPartyTarget(5);
        }
        var partyPosition6RectCollision = this.party_character6.getRectCollision();
        partyPosition6RectCollision.addEventListener("click", changePartyTarget6);
        function changePartyTarget6() {
            this.party_character_position7.setPartyTarget(6);
        }
        var partyPosition7RectCollision = this.party_character7.getRectCollision();
        partyPosition7RectCollision.addEventListener("click", changePartyTarget7);
        function changePartyTarget7() {
            this.party_character_position7.setPartyTarget(7);
        }
        var partyPosition8RectCollision = this.party_character8.getRectCollision();
        partyPosition8RectCollision.addEventListener("click", changePartyTarget8);
        function changePartyTarget8() {
            this.party_character_position7.setPartyTarget(8);
        }
        //コマンドの確認
    }

    _inputPosition8()
    {
        var partyPosition1RectCollision = this.party_character1.getRectCollision();
        partyPosition1RectCollision.addEventListener("click", changePartyTarget1);
        function changePartyTarget1() {
            this.party_character_position8.setPartyTarget(1);
        }
        var partyPosition2RectCollision = this.party_character2.getRectCollision();
        partyPosition2RectCollision.addEventListener("click", changePartyTarget2);
        function changePartyTarget2() {
            this.party_character_position8.setPartyTarget(2);
        }
        var partyPosition3RectCollision = this.party_character3.getRectCollision();
        partyPosition3RectCollision.addEventListener("click", changePartyTarget3);
        function changePartyTarget3() {
            this.party_character_position8.setPartyTarget(3);
        }
        var partyPosition4RectCollision = this.party_character4.getRectCollision();
        partyPosition4RectCollision.addEventListener("click", changePartyTarget4);
        function changePartyTarget4() {
            this.party_character_position8.setPartyTarget(4);
        }
        var partyPosition5RectCollision = this.party_character5.getRectCollision();
        partyPosition5RectCollision.addEventListener("click", changePartyTarget5);
        function changePartyTarget5() {
            this.party_character_position8.setPartyTarget(5);
        }
        var partyPosition6RectCollision = this.party_character6.getRectCollision();
        partyPosition6RectCollision.addEventListener("click", changePartyTarget6);
        function changePartyTarget6() {
            this.party_character_position8.setPartyTarget(6);
        }
        var partyPosition7RectCollision = this.party_character7.getRectCollision();
        partyPosition7RectCollision.addEventListener("click", changePartyTarget7);
        function changePartyTarget7() {
            this.party_character_position8.setPartyTarget(7);
        }
        var partyPosition8RectCollision = this.party_character8.getRectCollision();
        partyPosition8RectCollision.addEventListener("click", changePartyTarget8);
        function changePartyTarget8() {
            this.party_character_position8.setPartyTarget(8);
        }
    }


}
