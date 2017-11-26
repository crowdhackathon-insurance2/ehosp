<?php

namespace Insurance\Http\Controllers\API;

use Illuminate\Http\Request;
use Insurance\Http\Controllers\Controller;

class Validation extends Controller
{
    public function step1()
    {
        // POST card_id that was checked in and send SMS with extra password
        return 'validation step1';
    }

    public function step2()
    {
        // POST extra password received from SMS from step1
        return 'validation step2';
    }
}