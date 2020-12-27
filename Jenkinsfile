pipeline
{
    agent none
    stages
    {
		stage("Build compiler docker image")
		{
			agent
			{
				label "linuxdocker"
			}
			steps
			{
				dir("docker-cross")
				{
					sh './create-image.sh'
				}
			}
		}
		stage('Build')
		{
			agent
			{
				label "linuxdocker"
			}
			stages
			{
				stage("X86")
				{							
					steps
					{
						sh   './scripts/host/compile.sh clean'
						sh   './scripts/host/compile.sh x86'
					}

				stage("ARM")
					{
						steps
						{
							sh   './scripts/host/compile.sh arm'
						}
				}
			}
			
		}		
		stage('Unit tests')
		{
			parallel 
			{
				stage('Linux')
				{
					agent
					{
						label "linuxdocker"
					}
					stages
					{
						stage("X86")
						{
							steps
							{
								sh './scripts/host/run-tests.sh x86 --gtest_output=\"xml:reports/linux_x86_unit_test_report.xml\"'
							}

						}
						stage("ARM")
						{
							steps
							{
								sh './scripts/host/run-tests.sh arm --gtest_output=\"xml:reports/linux_arm_unit_test_report.xml\"'
							}
						}
					}
				}
			}
		}				   
    
	}
}