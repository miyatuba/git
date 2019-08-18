using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Main : MonoBehaviour
{
    //public GameObject input_object;
    public GameObject cursor_object;

    public GameObject album_object;
    public GameObject game_config_object;
    public GameObject game_start_object;
    public GameObject picture_book_object;

    private const int ALBUM_TYPE_ID = 1;
    private const int GAME_CONFIG_TYPE_ID = 2;
    private const int GAME_START_TYPE_ID = 3;
    private const int PICTURE_BOOK_TYPE_ID = 4;

    // Start is called before the first frame update
    void Start()
    {
        this.album_object.GetComponent<SelectTargetItem>().setId(ALBUM_TYPE_ID);
        this.game_config_object.GetComponent<SelectTargetItem>().setId(GAME_CONFIG_TYPE_ID);
        this.game_start_object.GetComponent<SelectTargetItem>().setId(GAME_START_TYPE_ID);
        this.picture_book_object.GetComponent<SelectTargetItem>().setId(PICTURE_BOOK_TYPE_ID);

        this.cursor_object.GetComponent<Cursor>().SelectCursorChangeById(this.album_object.GetComponent<SelectTargetItem>().getId());
    }

    // Update is called once per frame
    void Update()
    {
        //this.input_obj.GetComponent<InputManager>().InputCheck();

        GameObject clicked_game_object = null;

        if (Input.GetMouseButtonDown(0))
        {
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            RaycastHit2D hit2d = Physics2D.Raycast((Vector2)ray.origin, (Vector2)ray.direction);

            if (hit2d)
            {
                clicked_game_object = hit2d.transform.gameObject;
            }

        }

        if (clicked_game_object != null)
        {
            this.cursor_object.GetComponent<Cursor>().SelectCursorChangeById(clicked_game_object.GetComponent<SelectTargetItem>().getId());
        }



        //this.input_obj.GetComponent<InputManager>().LoopReset();
    }
}
