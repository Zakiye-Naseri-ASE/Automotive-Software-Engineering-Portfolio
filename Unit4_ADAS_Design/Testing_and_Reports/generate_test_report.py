import csv

def generate_report(data_file):
    total_tests = 0
    passed_tests = 0
    
    report = ["# Unit 5: ecu.test Execution Summary\n"]
    report.append("| Test Case | Module | Status | Time (ms) |")
    report.append("|-----------|--------|--------|-----------|")
    
    with open(data_file, mode='r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            total_tests += 1
            if row['Result'] == 'SUCCESS':
                passed_tests += 1
                status_icon = "✅ PASS"
            else:
                status_icon = "❌ FAIL"
                
            report.append(f"| {row['Test_Case_ID']} | {row['Module']} | {status_icon} | {row['Execution_Time_ms']} |")
            
    success_rate = (passed_tests / total_tests) * 100
    report.insert(1, f"**Overall Success Rate:** {success_rate}%\n")
    
    with open('Unit5_Final_Report.md', 'w') as out:
        out.write('\n'.join(report))
    print("Unit 5 Report Generated.")

if __name__ == "__main__":
    generate_report('ecu_test_results.csv')