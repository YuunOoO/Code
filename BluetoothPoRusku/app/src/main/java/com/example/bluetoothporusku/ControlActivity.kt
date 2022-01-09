package com.example.bluetoothporusku
import android.bluetooth.BluetoothManager
import com.example.bluetoothporusku.databinding.ActivityControlBinding
import android.content.*
import android.content.Context
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import android.view.View
import android.widget.Toast
import androidx.activity.result.ActivityResultLauncher
import androidx.activity.result.contract.ActivityResultContracts




class ControlActivity : AppCompatActivity() {
    private lateinit var binding: ActivityControlBinding
    private lateinit var actListLauncher: ActivityResultLauncher<Intent>
    lateinit var btConnection: BtConnection
    private var listItem: ListItem? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityControlBinding.inflate(layoutInflater)
        setContentView(binding.root)
        onBtListResult()
        init()

        //
        val bluetoothManager= applicationContext.getSystemService(BLUETOOTH_SERVICE) as BluetoothManager
        val bluetoothAdapter= bluetoothManager.adapter
        binding.btnON.setOnClickListener(View.OnClickListener {
            bluetoothAdapter.enable()
            Toast.makeText(applicationContext,"Nastapilo polaczenie BlueTooth", Toast.LENGTH_SHORT).show()
            //val intent=Intent()
            //startActivityForResult(intent, 1)
        })
        binding.btnOFF.setOnClickListener(View.OnClickListener {
            bluetoothAdapter.disable()
            Toast.makeText(applicationContext,"BlueTooth zostal rozlaczony", Toast.LENGTH_SHORT).show()
        })
        //

        binding.apply {
            bA.setOnClickListener {
                btConnection.sendMessage("a")
            }
            bB.setOnClickListener {
                btConnection.sendMessage("b")
            }
        }

    }

    private fun init(){
        val btManager = getSystemService(Context.BLUETOOTH_SERVICE) as BluetoothManager
        val btAdapter = btManager.adapter
        btConnection = BtConnection(btAdapter)
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.control_menu, menu)
        return super.onCreateOptionsMenu(menu)
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        if(item.itemId == R.id.id_list){
            actListLauncher.launch(Intent(this, BtListActivity::class.java))
        } else if(item.itemId == R.id.id_connect){
            listItem.let {
                btConnection.connect(it?.mac!!)
            }
        }
        return super.onOptionsItemSelected(item)
    }

    private fun onBtListResult(){
        actListLauncher = registerForActivityResult(
            ActivityResultContracts.StartActivityForResult()){
            if(it.resultCode == RESULT_OK){
                listItem = it.data?.getSerializableExtra(BtListActivity.DEVICE_KEY) as ListItem
            }
        }
    }
}