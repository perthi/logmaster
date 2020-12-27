


pipeline
{
    agent any

	stages
	{
		stage("Build")
		{	
			stages
			{	
				stage("Build compiler docker image")
				{
					steps
					{
						dir("docker-cross")
						{	
							sh 'whoami'
							sh './create-image.sh'
						}
					}
				}
				stage("X86")
				{							
					steps
					{
						sh   './scripts/host/compile.sh clean'
						sh   './scripts/host/compile.sh x86'
					}
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
		stage("Unit tests")
		{
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

