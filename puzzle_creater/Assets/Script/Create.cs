using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Create : MonoBehaviour
{
    private GameObject move_object; 

    public GameObject prefab;

    void Start()
    {
        this.move_object = (GameObject)Resources.Load("Prefab/" + this.prefab.name);
    }

    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            Ray ray = new Ray();
            RaycastHit hit = new RaycastHit();
            ray = Camera.main.ScreenPointToRay(Input.mousePosition);

            if (Physics.Raycast(ray.origin, ray.direction, out hit, Mathf.Infinity) && hit.collider == this.gameObject.GetComponent<Collider>())
            {
                // Cubeプレハブを元に、インスタンスを生成
                Instantiate(this.move_object, new Vector3(this.transform.rotation.x, this.transform.rotation.y, this.transform.rotation.z), Quaternion.identity);

            }
            else
            {

            }
        }
        
        //クリックするイベント
        //this.MoveObject();

        if (Input.GetMouseButtonUp(0))
        {
        }
    }

}
