package com.example.bluetoothporusku

import java.io.Serializable

data class ListItem(
    var name: String,
    var mac: String
): Serializable
