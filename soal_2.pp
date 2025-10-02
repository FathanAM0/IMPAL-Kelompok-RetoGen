program ServisKomputer;

var
    computer_amount, is_business_hours, is_willing_dropoff: Integer;
    base_fee, additional_fee, total_base_fee, total_fee: Integer;
    peripheral_count: Integer;
    pilihan: Char;

begin
    repeat
        WriteLn('=== SERVIS KOMPUTER ===');
        
        Write('Jumlah komputer: ');
        ReadLn(computer_amount);
        
        Write('Jumlah peripheral: ');
        ReadLn(peripheral_count);
        
        Write('Waktu servis (0 = di luar jam bisnis, 1 = dalam jam bisnis): ');
        ReadLn(is_business_hours);
        
        Write('Pelanggan bersedia drop off & pick up (0 = tidak, 1 = ya): ');
        ReadLn(is_willing_dropoff);
        
        if (computer_amount = 1) or (computer_amount = 2) then
        begin
            base_fee := 50;
            additional_fee := 0;
        end
        else if (computer_amount >= 3) and (computer_amount <= 10) then
        begin
            base_fee := 100;
            additional_fee := 10 * peripheral_count;
        end
        else if computer_amount > 10 then
        begin
            base_fee := 500;
            additional_fee := 10 * peripheral_count;
        end
        else
        begin
            WriteLn('Jumlah komputer tidak valid!');
            WriteLn;
            Write('Ulangi lagi? (Y/N): ');
            ReadLn(pilihan);
            if UpCase(pilihan) <> 'Y' then
                Exit;
            Continue;
        end;
        
        total_base_fee := base_fee;
        
        if is_business_hours = 0 then
        begin
            total_base_fee := base_fee * 2;
        end;
        
        if is_willing_dropoff = 1 then
        begin
            total_base_fee := total_base_fee div 2;
        end;
        
        total_fee := total_base_fee + additional_fee;
        
        WriteLn;
        WriteLn('=== RINCIAN BIAYA SERVIS ===');
        WriteLn('Base fee: $', base_fee);
        WriteLn('Additional fee (peripheral): $', additional_fee);
        
        if is_business_hours = 0 then
        begin
            WriteLn('Biaya diluar jam bisnis: base fee dikalikan 2');
        end;
        
        if is_willing_dropoff = 1 then
        begin
            WriteLn('Diskon drop off & pick up: base fee dikurangi 50%');
        end;
        
        WriteLn('Total base fee: $', total_base_fee);
        WriteLn('Total biaya servis: $', total_fee);
        
        WriteLn;
        Write('Hitung servis lagi? (Y/N): ');
        ReadLn(pilihan);
        WriteLn;
        
    until UpCase(pilihan) <> 'Y';
    
    WriteLn('Terima kasih telah menggunakan program servis komputer!');
end.