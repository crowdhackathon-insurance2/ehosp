<?php

namespace Insurance\Http\Controllers\API;

use Illuminate\Http\Request;
use Insurance\Http\Controllers\Controller;

class Validation extends Controller
{
    public function step1(Request $request)
    {
        // POST card_id that was checked in and send SMS with extra password
        return $request->input('card_id');
    }

    public function step2(Request $request)
    {
        // POST extra password received from SMS from step1
        return $request->input('passcode');
    }
}
