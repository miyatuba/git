class BattleInput {
    constructor()
    {

    }

    setTest(rect)
    {
        // �e��}�E�X�C�x���g��o�^����
        rect.addEventListener("click", handleRectClick);
        // �N���b�N�����Ƃ�
        function handleRectClick(event) {
            alert("�l�p�`���N���b�N����܂���");
        }
    }
}